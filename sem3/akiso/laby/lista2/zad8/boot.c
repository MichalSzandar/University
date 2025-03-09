// boot.c
// Simple modification of https://github.com/mars-research/hello-os that prints "Hello, World!" in all possible color combinations
void print(char *message, char *video_memory, unsigned char color){
    for(int i = 0; message[i] != '\0'; i++){
        video_memory[i*2] = message[i];
        video_memory[i*2 + 1] = color;
    }
}

void main() {
    char *video_memory = (char*) 0xB8000;
    char *message = "Hello, World!                          ";
    int line = 1;
    for(unsigned char bg = 0; bg<16; bg++){
        for(unsigned char fg = 0; fg<16; fg++){
            unsigned char color = (bg<<4) | fg;
            print(message, video_memory, color);
	    video_memory += 80 * 2;
            line++;
            if(line>=25) {
                line = 1;
                video_memory = (char*) 0xB8000;
            }
            for(volatile int delay = 0; delay<100000000; delay++);
        }
    }
    while(1);
}
