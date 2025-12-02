#include <stdint.h>

#define BUFFER_SIZE 128

typedef struct CircularBuffer {
	uint8_t buffer[BUFFER_SIZE];
	volatile uint32_t head;
	volatile uint32_t tail;
} CircularBuffer;

CircularBuffer* createBuffer() {
	CircularBuffer *b = malloc(sizeof(CircularBuffer));
	b->head = 0;
	b->tail = 0;
	return b;
}

/**
 *  0 - No errors
 * -1 - an error occured
 */
int buffer_write(CircularBuffer *buffer, uint8_t byte) {
	uint32_t nextHead = (buffer->head + 1) & (BUFFER_SIZE - 1);
	if(nextHead == buffer->tail) {
		//buffer is full, throw an error
		return -1;
	}

	buffer->buffer[buffer->head] = byte;
	buffer->head = nextHead;
	return 0;
}

/**
 *  0 - No errors
 * -1 - an error occured
 */
int buffer_read(CircularBuffer *buffer, uint8_t *data) {
	if(buffer->head == buffer->tail) return -1;

	*data = buffer->buffer[buffer->tail];
	buffer->tail = (buffer->tail + 1) & (BUFFER_SIZE - 1);
	return 0;
}