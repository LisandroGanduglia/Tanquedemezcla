# Memoria descriptiva

Mi sistema representa un tanque con un motor donde se realiza una mezcla de dos componentes para obtener un nuevo compuesto.  Los niveles serán medidos por un único sensor ultrasonico, tanto el tiempo de trabajo del motor como los niveles de cada liquido pueden configurarse según los requerimiento del usuario.

Al encenderse el sistema se abre la válvula A donde ingresa el primer componente, cuando llega al nivel deseado, se cierra la válvula A y se abre la válvula B hasta que el segundo componete llegue al nivel deseado, una vez finalizada la carga se cierra la válvula B y se acciona el motor que facilitara la mezcla, luego de cierto tiempo se detiene el motor y se abre la válvula C por donde saldrá el nuevo compuesto.
<p align="center">
  <img width="500" height="500" src="https://github.com/LisandroGanduglia/Tanquedemezcla/blob/main/recursos/esquematanque.png">
</p>

## Maquina de estado
<p align="center">
  <img width="500" height="500" src="https://github.com/LisandroGanduglia/Tanquedemezcla/blob/main/recursos/maquinadeestado.png">
</p>

- SET: Bandera de fin de inicialización

- n: Nivel leído

- na_set: Nivel configurado del liquido A

- nb_set: Nivel configurado del liquido b

- t: Tiempo del motor activo leído

- tm_set: Tiempo configurado para el motor activo