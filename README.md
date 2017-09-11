IoTnet_DEVKIT
=============

-	[Introducción](#introducción)

-	[Pinout](#pinout)

-	[Ejemplos](#ejemplos)

	-	[Leer ID/PAC](#leer-idpac)

	-	[Boton y led](#boton-y-led)
	
	-	[Sensor de distancia](#sensor de distancia)

Introducción
------------

Proyecto para aprender a utilizar el Devkit de desarrollo de IoTnet, el cual trae un módulo Wisol de conectividad Sigfox y un microprocesador ATmega 328P, por lo que puede programarse mediante el IDE de Arduino.
El Devkit cuenta con 6 GPIOs y 6 entradas analógicas, que tambien pueden configurarse como entradas digitales, un botón y un led que pueden programarse. 
A lo largo de este proyecto, se presentaran algunos ejemplos para demostrar lo fácil que es incluir la conectividad Sigfox a cualquier proyecto. Además, los ejemplos permitiran asociar las terminales de la tarjeta con las utilizadas en Arduino de manera que cualquier sketch utilizado en Arduino Uno puede ser cargado en el Devkit, unicamente cambiando los puertos utilizados a los disponibles en la tarjeta.

Pinout

En la siguiente imagen se muestra el pinout del Devkit, de manera que se puedan asociar las terminales de la tarjeta con las utilizadas en Arduino Uno. 

![devkit_pinout](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/devkit_pinout.jpg?raw=true)

Ejemplos
--------
A continuación se presentan varios ejemplos donde se utilizan las entradas analogicas y digitales, además de los dispositivos integrados en el Devkit.  

### Leer ID/PAC

En este ejemplo se utilizará el sketch devkit_info.ino ([Code](Ejemplos/devkit_info/devkit_info.ino)) para leer el ID y el PAC de nuestro Devkit, los cuales son necesarios para registrar el dispositivo en la plataforma de Sigfox y poder ver los mensajes enviados en el backend. Una vez descargado el sketch, procedemos a cargarlo en nuestra tarjeta. Primero, se deben de quitar los jumpers tal como se muestra en la imagen de abajo. Este procedimiento debe hacerse siempre que se desee cargar un programa a la tarjeta.

![dev1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev1.png?raw=true)

Despues, verificamos o compilamos el programa y lo cargamos a la tarjeta. Volvemos a poner los jumpers para reestablecer la comunicacion entre el microcontrolador y el modulo Wisol y abrimos el Monitor Serie 

![dev2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev2.png?raw=true)

Presionamos el botón más cercano al Led que se encuentra encendido y en el monitor serial nos aparecerá la información sobre el ID y el PAC de nuestro Devkit.

![dev3](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev3.png?raw=true)

Ahora que tenemos el ID y el Pac de nuestro dispositivo, procedemos a darlo de alta en el backend. Una vez registrado, podemos enviar nuestro primer mensaje, lo cual podemos hacer con el mismo programa. Presionamos nuevamente el boton y nos desplegara la misma información que antes. Notar que los leds de status del modulo Wisol parpadearan 3 veces, lo que indica que se estan enviando los mensajes. Si nos vamos al backend, veremos el mensaje que acabamos de enviar.

![dev4](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev4.png?raw=true)

### Boton y led

Este ejemplo nos permitira conocer cuales son los puertos a los que estan conectados el boton y el led 6 para poder utilizarlos en otros programas. Se utilizará el sketch boton_led.ino ([Code](Ejemplos/boton_led/boton_led.ino)). Una vez cargado el programa, al presionar el botón, el Led 6 se encenderá por 2 segundos para despues apagarse.

![dev5](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev5.png?raw=true)

### Sensor de distancia

En este ejemplo se mostrará como conectar un sensor de distancia al Devkit y mandar por medio de Sigfox, la distancia medida entre el sensor y un objeto, de manera que pueda visualizarse en el backend. El sensor que se utilizará es el HC-SRQ4. Conectamos el sensor de acuerdo al siguiente diagrama

![sensor_distancia](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/sensor_distancia.jpg?raw=true)

Descargamos el sketch sensor_distancia1.ino ([Code](Ejemplos/sensor_distancia1/sensor_distancia1.ino)) y lo cargamos en la tarjeta siguiendo el procedimiento descrito anteriormente. Ponemos un objeto enfrente del sensor

![dev6](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev6?raw=true)
