package operand;

public class Operand {
  String token;
  int value;

//converts string token tp integer value
  public Operand( String token ) {
    this.token = token;
    this.value = Integer.parseInt(token);
  }

//converts integer value to string token 
  public Operand( int value ) {
    this.value = value;
    this.token = Integer.toString(value);
  }

public int getValue() {
      return value;
  }

  //checks if token is a valid integer
  public static boolean check(String token) {
    try {
      Integer.parseInt(token);
      return true;
    } catch (NumberFormatException e) {
      return false;
    }
  }
  
}
