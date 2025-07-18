# IoT Socket Communication Project

This project demonstrates TCP socket communication between a **Qt GUI server** and a **headless QEMU client**.

## Structure

- `server/`: Qt GUI that listens on port 1234 and shows incoming messages.
- `client/`: Command-line tool that connects to the server and sends `ON`.

## Run Instructions

### Host (Qt GUI Server)

```bash
cd server
mkdir -p build && cd build
cmake ..
make
./server
