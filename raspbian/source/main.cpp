#include "libspi.h"
#include <stdio.h>
#include <unistd.h>

int main(void){
    
    SPI *spi;
    spi = new SPI( 0, 0, SPI_CPOL | SPI_CPHA);

    uint8_t packet[2];
    uint8_t *rxbuf;

    
    packet[0] = 0xaa;
    packet[1] = 0x00;

    while(true){
        for(int i = 0;i <= 1;i++){
            rxbuf = spi->transfer(1,&packet[i]);
            if(i == 0){
                printf("send 0xaa\n");
            }
            else{
                printf("send 0x00\n");
            }
            printf("%d\n",*rxbuf);
            sleep(1);
        }
    }
    delete(spi);
    return 0;
}

