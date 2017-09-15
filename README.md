IoTnet_DEVKIT
=============

-	[Introducción](#introducción)

-	[Pinout](#pinout)

-	[Programación](#programacion)

-	[Ejemplos](#ejemplos)

	-	[Leer ID/PAC](#leer-idpac)

	-	[Boton y led](#boton-y-led)
	
	-	[Sensor ultrasónico](#sensor-ultrasónico)

	-	[Sensor de Temperatura](#sensor-de-temperatura)
	
-	[Integración en Losant](#integración-en-losant)

Introducción
------------

Proyecto para aprender a utilizar el Devkit de desarrollo de IoTnet, el cual trae un módulo Wisol de conectividad Sigfox y un microprocesador ATmega 328P, por lo que puede programarse mediante el IDE de Arduino (https://www.arduino.cc/en/Main/Software).
El Devkit cuenta con 6 GPIOs y 6 entradas analógicas, que también pueden configurarse como entradas digitales, un botón y un led que pueden programarse. 
A lo largo de este proyecto, se presentarán algunos ejemplos para demostrar lo fácil que es incluir la conectividad Sigfox a cualquier proyecto. Además, los ejemplos permitirán asociar las terminales de la tarjeta con las utilizadas en Arduino de manera que cualquier sketch utilizado en Arduino Uno puede ser cargado en el Devkit, únicamente cambiando los puertos utilizados a los disponibles en la tarjeta.

Pinout
------

En la siguiente imagen se muestra el pinout del Devkit, de manera que se puedan asociar las terminales de la tarjeta con las utilizadas en Arduino Uno. 

![devkit_pinout](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/devkit_pinout.jpg?raw=true)

Programación
------------

Para cargar un programa a la tarjeta, primero se deben quitar los jumpers tal como se muestra en la imagen. TENER CUIDADO AL QUITAR LOS JUMPERS.

![dev1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev1.png?raw=true)

una vez que se cargó el programa, se vuelven a colocar los jumpers. Este procedimiento debe realizarse cada vez que se desee cargar un programa al Devkit.

Ejemplos
--------
A continuación, se presentan varios ejemplos donde se utilizan las entradas analógicas y digitales, además de los dispositivos integrados en el Devkit.  

### Leer ID/PAC

En este ejemplo se utilizará el sketch devkit_info.ino ([Code](Ejemplos/devkit_info/devkit_info.ino)) para leer el ID y el PAC de nuestro Devkit, los cuales son necesarios para registrar el dispositivo en la plataforma de Sigfox y poder ver los mensajes enviados en el backend. Una vez descargado el sketch, procedemos a cargarlo en nuestra tarjeta siguiendo el procedimiento descrito anteriormente.
Abrimos el Monitor Serie 

![dev2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev2.png?raw=true)

Presionamos el botón más cercano al Led que se encuentra encendido y en el monitor serial nos aparecerá la información sobre el ID y el PAC de nuestro Devkit.

![dev3](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev3.png?raw=true)

Ahora que tenemos el ID y el Pac de nuestro dispositivo, procedemos a darlo de alta en el backend. Una vez registrado, podemos enviar nuestro primer mensaje, lo cual podemos hacer con el mismo programa. Presionamos nuevamente el botón y nos desplegara la misma información que antes. Notar que los leds de status del módulo Wisol parpadearan 3 veces, lo que indica que se están enviando los mensajes. Si nos vamos al backend, veremos el mensaje que acabamos de enviar.

![dev4](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev4.png?raw=true)

### Boton y led

Este ejemplo nos permitirá conocer cuáles son los puertos a los que están conectados el botón y el led para poder utilizarlos en otros programas. Se utilizará el sketch boton_led.ino ([Code](Ejemplos/boton_led/boton_led.ino)). Una vez cargado el programa, al presionar el botón, el Led 6 se encenderá por 2 segundos para después apagarse.

![dev5](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev5.png?raw=true)

### Sensor ultrasónico

En este ejemplo se mostrará como conectar un sensor de distancia al Devkit y mandar por medio de Sigfox, la distancia medida entre el sensor y un objeto, de manera que pueda visualizarse en el backend. El sensor que se utilizará es el HC-SRQ4. Conectamos el sensor de acuerdo al siguiente diagrama

![sensor_distancia](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/sensor_distancia.jpg?raw=true)

Descargamos el sketch sensor_distancia1.ino ([Code](Ejemplos/sensor_distancia1/sensor_distancia1.ino)) y lo cargamos en la tarjeta siguiendo el procedimiento descrito anteriormente. El programa manda la información de la distancia hacia el backend cada 10 minutos.

Ponemos un objeto frente al sensor

![dev6](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev6.png?raw=true)

y abrimos el monitor serial de Arduino. Inmediatamente nos mostrara la distancia medida entre el sensor y el objeto

![dev7](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev7.png?raw=true)

Si revisamos el backend, veremos que cada mensaje nos mostrara la misma información de la distancia que la mostrada en el monitor serie

![back1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/back1.png?raw=true)

### Sensor de Temperatura

En este ejemplo se mostrará como leer un sensor analógico además de realizar la codificación del dato antes de ser enviado y ya en el backend, se realizará la decodificación para poder visualizar la información en forma decimal. 

Descargar el sketch ([Code](Ejemplos/sensor_temperatura/sensor_temperatura.ino)). El sensor utilizado en este ejemplo es el TMP36

![tmp36](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/tmp36.jpg?raw=true)

el cual debe ser conectado siguiendo el siguiente diagrama

![temp2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/temp2.png?raw=true)

Una vez cargado el programa, abrimos el monitor serial y nos desplegara la información de la temperatura cada 5 minutos

![dev8](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev8.png?raw=true)

Ahora para decodificar el dato enviado, se debe realizar el parsing del payload. Ir al “Device type” donde se encuentra el dispositivo y dar click en el botón “Edit” en la esquina superior derecha y en la sección “Payload display” seleccionamos “Custom grammar” y en “Custom configuration” escribimos temp::float:32:little-endian 

![dev10](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev10.png?raw=true)

Revisando los mensajes del dispositivo, veremos que ahora debajo del dato enviado aparecerá la información de la temperatura tal como nos aparece en el monitor serie de Arduino

![dev9](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/dev9.png?raw=true)


Integración en Losant
---------------------
Para esta parte utilizaremos el ejemplo del sensor de temperatura anterior. 

Ahora que el backend está recibiendo los mensajes del módulo. Procederemos a visualizar los datos en [Losant](https://www.losant.com/), plataforma dedicada al internet de las cosas. En donde se pueden visualizar, analizar datos provenientes de dispositivos IoT.


Comenzaremos por crear una cuenta gratuita. Ésta nos permite registrar hasta 100 dispositivos y enviar hasta 1M de payloads.
Creada la cuenta crearemos una nueva aplicación. Además es facil de usar ya que se configura por medio de diagramas de flujo.

![create](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/create.png?raw=true)

EL nombre de la aplicación puede ser cualquiera. Pero que sea facil de reconocer. 
Seguido daremos click en 'Create Application'

![create2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/create2.png?raw=true)

Dentro de nuestra aplicacíon configuraremos 3 cosas: 

1: Webhook - Url en donde se enviarán todos los datos desde el backend a la plataforma
2: Device - Dispositivo en donde Losant guardará la informacion proveniente del Devkit para posteriormente mostrarla en un dashboard
3: Workflow - Diagrama de flujo que se activará cada vez que haya un request por parte del backend de Sigfox

### Webhook

Dentro de nuestra aplicación nos dirigimos a la pestaña 'Webhooks' y damos click.

![webhook](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/webhook.png?raw=true)

Damos click en 'Add Webhook' y aparecerá la siguiente ventana en donde configuraremos lo siguiente: 
 - El nombre de nuevo puede ser cualquiera y lo demás lo dejamos con la misma configuración
 
![webhook2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/webhook2.png?raw=true)

Mas abajo marcamos la opción 'Wait for reply from workflow' y seguido damos click en 'Create Webhook"

![webhook4](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/webhook4.png?raw=true)

Notaremos que al momento de crearlo nos genera una URL: 

![webhook5](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/webhook5.png?raw=true)

Esta URL la copiaremos y guardaremos para usarla posteriormente para configurar el callback de Sigfox

### Device

Ahora, configuraremos el device en donde Losant guardará los datos provenientes de Sigfox
En nuestra pantalla principal de la aplicacion, daremos click en 'Devices', seguido daremos click en 'Create new device'

![createdev](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/createdev.png?raw=true)

Damos click en 'Create blank device'

![createdev1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/createdev1.png?raw=true)

En el Device Name podemos poner el nombre que queramos pero de preferencia que indentifique a nuestro dispositivo
Marcamos la casilla 'Standalone' en el Device Type

![createdev2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/createdev2.png?raw=true)

En la parte de atributos colocamos: 

![createdev3](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/createdev3.png?raw=true)

Debemos de tener en cuenta que información estamos leyendo y enviando desde el dispositivo.
En este caso estamos enviando unicamente la temperatura del sensor por lo que el tipo de dato que recibira Losant será un número y el nombre de la variable puede ser cualquier pero de nuevo una que identifique nuestra información.


### Workflow

Ahora es turno de configurar el diagrama de flujo para que una vez que Losant reciba la información sepa que hacer con ella.

En nuestro menú principal de la aplicación damos click en 'Workflows', seguido damos click en 'Create Workflow'

Le damos el nombre que nosotros queramos y opcionalmente podemos asignarle una descripción.
Seguido damos click en 'Create Workflow'

Notaremos que nos abrirá un espacio de trabajo donde podremos crear nuestro diagrama de flujo.

Del lado izquierdo nos muestra todos los nodos disponibles. Tales como 'Triggers', 'User Experience', 'Data', etc.

Debido a que nuestra información esta llegando por medio de un Webhook, el diagrama de flujo se activará cada que llegue información a ese Webhook que creamos.

Por lo tanto, en el lado izquierdo en la sección de 'Triggers' buscamos por el nodo 'Webhook'

![workflow](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/workflow.png?raw=true)

Lo arrastramos y pegamos a nuestro espacio de trabajo.

![workflow1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/workflow1.png?raw=true)

Ahora, buscaremos el nodo 'Debug'. Este nodo nos sirve para observar que esta sucediendo en determinada parte del diagrama de flujo. Lo conectaremos debajo de nuestro 'Webhook' para poder observar que información llega.

![workflow2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/workflow2.png?raw=true)

Dejaremos esta parte pendiente para continuar configurando el backend en Sigfox.


### Backend 

Para esta parte es necesario haber registrado el dispositivo en el backend de Sigfox.
Daremos click en 'Device Type' y buscamos por nuestro dispositivo registrado

![backend1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/backend1.png?raw=true)

Dentro de nuestro Device Type, del lado izquierdo en el menú buscamos la opción 'Callbacks' y damos click

![backend2](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/backend2.png?raw=true)

Los callbacks nos sirven para poder jalar nuestra información del backend Sigfox a nuestra webApp, plataforma, etc.
Para nuestro ejemplo haremos un callback a Losant

Dentro de la sección 'Callbacks' damos click en 'New', seguido daremos click en 'Custom Callback'

![callback](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/callback.png?raw=true)

En la ventana que nos aparece, configuraremos nuestro callback de la siguiente manera:

![callback1](https://github.com/Iotnet/IoTnet_DEVKIT/blob/master/images/callback1.png?raw=true)

-	Type : Data & Uplink
-	Channel: URL // 
- 	Custom Payload Config : Variables personalizadas, decodificación del mensaje hexadecimal
-	URL Pattern : URL a la que le enviaremos la información del dispositivo
-	Use HTTP method : POST	
-	Content type : Application/json


Así nuestro callback quedará listo para poder recibir la información en Losant.
