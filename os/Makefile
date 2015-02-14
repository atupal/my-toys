
kernel: bios
	gcc -ffreestanding -c kernel.c -o kernel.o
	ld -Ttext 0x1000 kernel.o --oformat binary  -o kernel.bin 
	cat boot_sect.bin kernel.bin zero > os-image

run:
	qemu-system-i386 os-image
	# bochs -f bochs.conf

bios:
	nasm boot_sect.asm -f bin -o boot_sect.bin

run_bios:
	# bochs
	qemu-system-i386 boot_sect.bin

hex:
	od -t x1 -A n boot_sect.bin
