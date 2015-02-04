
all:
	nasm boot_sect.asm -f bin -o boot_sect.bin

run:
	# bochs
	qemu-system-i386 boot_sect.bin

hex:
	od -t x1 -A n boot_sect.bin
