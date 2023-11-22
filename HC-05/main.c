#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define uart_id uart0
#define baud 38400

void init_uart(){
    uart_init(uart_id, 38400);
    gpio_set_function(16,GPIO_FUNC_UART);
    gpio_set_function(17, GPIO_FUNC_UART);

    uart_set_format(uart_id, 8, 1, UART_PARITY_NONE);
    uart_set_hw_flow(uart_id,false,false);
}

void write(char c){
    uart_putc(uart_id, c);
}

int main(){
    stdio_init_all();
    init_uart();

    char c;

    while(true){
        if(uart_is_readable(uart_id)){
            c = uart_getc(uart_id);
            printf("%c",c);
        }

        if(stdio_is_rx_ready()){
            c = getchar();
            write(c);
            if(c=="\n"){
                printf(">");
            }
        }
        
        if(stdio_is_rx_ready()){
            c = getchar();
            write(c);
            if(c=="\n"){
                printf(">");
            }
    }
}
