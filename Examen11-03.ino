/*	
 *  Controlar un RGB dede un potenciometro y mapear su estado 
 *	Realizado por: David Cespón Míguez 
 *  Data: 11/03/2024
*/
// Definir los pines del LED RGB
const int redPin = 6;
const int greenPin = 3;
const int bluePin = 5;

// Definir el pin del potenciómetro
const int potPin = A0;

void setup() {
  // Inicializar los pines del LED RGB como salidas
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Inicializar la comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del potenciómetro
  int potValue = analogRead(potPin);
  
  // Mapear el valor del potenciómetro al rango de colores
  int color = map(potValue, 0, 1023, 0, 3);
  
  // Establecer el color del LED RGB según el valor del potenciómetro
  switch (color) {
    case 0: // Rojo
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      // Imprimir valores en el monitor serie
      printColorValues(255, 0, 0);
      break;
    case 1: // Verde
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      // Imprimir valores en el monitor serie
      printColorValues(0, 255, 0);
      break;
    case 2: // Azul
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      // Imprimir valores en el monitor serie
      printColorValues(0, 0, 255);
      break;
    case 3: // Amarillo
      analogWrite(redPin, 255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      // Imprimir valores en el monitor serie
      printColorValues(255, 255, 0);
      break;
  }
}

// Función para imprimir los valores de los colores en decimal.
void printColorValues(int red, int green, int blue) {
  // Imprimir los valores en decimal
  Serial.print("Decimal: ");
  Serial.print(red);
  Serial.print(", ");
  Serial.print(green);
  Serial.print(", ");
  Serial.println(blue);

  

  // Espacio en blanco para separar las lecturas
  Serial.println();
}
 
