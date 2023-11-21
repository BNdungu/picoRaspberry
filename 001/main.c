//include the library
#include "pico/stdlib.h" 

#define GPIO_ON 1
#define GPIO_OFF 0

#define one 0
#define two 1
#define three 3
#define four 0

const uint pins[] = {0,1,2,3};

int main(){
	for(int i = 0; i < 4; i++){
			gpio_init(pins[i]);
		}
	// stdio_init_all();

	for(int i = 0; i < 4; i++){
			gpio_set_dir(pins[i], GPIO_OUT);
		}
	
	while(true){

		for(int i = 0; i < 4; i++){
			gpio_put(pins[i], GPIO_ON);
			sleep_ms(1000);
		}

		for(int i = 3; i >-1; i--){
			gpio_put(pins[i], GPIO_OFF);
			sleep_ms(1000);
		}
	}
}
