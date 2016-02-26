
C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
OBJ = $(C_SOURCES:.c=.o)

kernel: bios main_kernel.c zero ${OBJ}
	gcc -ffreestanding -c main_kernel.c -o kernel.o -m32
	# previously we have compiled assembly into a raw binary format, because we wanted
	# to run it as boot sector code on the CPU, but for this piece of code cannot stand alone,
	# without having that label resolved, so we must compile it as follows as an object file,
	# therefor preserving meta infomation about the labels it must resolve:
	#nasm kernel_entry.asm -f elf64 -o kernel_entry.o
	nasm kernel_entry.asm -f elf32 -o kernel_entry.o
	ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o	${OBJ} --oformat binary -melf_i386
	# ld -Ttext 0x1000 kernel.o --oformat binary  -o kernel.bin
	cat boot_sect.bin kernel.bin zero.bin > os-image

run: kernel
	#qemu-system-i386 os-image
	qemu-system-x86_64 os-image
	#bochs -f bochs.conf

run_bochs: kernel
	#qemu-system-i386 os-image
	#qemu-system-x86_64 os-image
	bochs -f bochs.conf

runb: kernel
	bochs -f bochs.conf

bios: boot_sect.asm
	nasm boot_sect.asm -f bin -o boot_sect.bin

%.o : %.c
	gcc -ffreestanding -c $< -o $@ -m32

run_bios:
	# bochs
	qemu-system-i386 boot_sect.bin

objdump:
	objdump -d kernel.o

dis:
	ndisasm -b 32 kernel.bin

hex:
	od -t x1 -A n boot_sect.bin

zero:
	dd if=/dev/zero of=./zero.bin bs=1M count=1

clean:
	rm -fr *.bin *.o
	rm -fr kernel/*.o drivers/*.o
	rm "os-image"
