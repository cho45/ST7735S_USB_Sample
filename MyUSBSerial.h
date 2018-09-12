#include "USBCDC.h"
#include "CircBuffer.h"
#include "stdint.h"

class MyUSBSerial: public USBCDC {
	private:
		Callback<void()> rx;
		CircBuffer<uint8_t,128> buf;

	public:
		MyUSBSerial(uint16_t vendor_id = 0x1f00, uint16_t product_id = 0x2012, uint16_t product_release = 0x0001, bool connect_blocking = true):
			USBCDC(vendor_id, product_id, product_release, connect_blocking){
			};

		bool writeBlock(void* b, uint16_t size) {
			uint8_t* buf = reinterpret_cast<uint8_t*>(b);
			if (!send(buf, size)) {
				return false;
			}

//			while (1) {
//				if (size < MAX_PACKET_SIZE_EPBULK) {
//					if (!send(buf, size)) {
//						return false;
//					}
//					break;
//				} else {
//					if (!send(buf, MAX_PACKET_SIZE_EPBULK)) {
//						return false;
//					}
//					buf  += MAX_PACKET_SIZE_EPBULK;
//					size -= MAX_PACKET_SIZE_EPBULK;
//				}
//			}
			return true;
		}
		uint8_t available() {
			return buf.available();
		}

		void read(uint16_t len, uint8_t out[]) {
			while (available() < len);
			for (uint16_t i = 0; i < len; i++) {
				buf.dequeue(&out[i]);
			}
		}

		uint8_t read() {
			uint8_t c = 0;
			while (available() < 1);
			buf.dequeue(&c);
			return c;
		}

		bool connected() const {
			return terminal_connected;
		}


	protected:
		virtual bool EPBULK_OUT_callback() {
			uint8_t c[MAX_PACKET_SIZE_EPBULK+1];
			uint32_t size = 0;

			//we read the packet received and put it on the circular buffer
			readEP(c, &size);
			for (uint32_t i = 0; i < size; i++) {
				buf.queue(c[i]);
			}

			//call a potential handlenr
			if (rx)
				rx.call();

			return true;
		}

		virtual void lineCodingChanged(int baud, int bits, int parity, int stop){
			// nothing to do
		}
};

