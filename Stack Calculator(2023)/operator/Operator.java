package operator;

import operand.Operand;
import java.util.HashMap;

public abstract class Operator {
  // HashMap will use tokens as keys and operator instances as values.
  private static HashMap<String, Operator> operators = new HashMap<>();

  // returns the priority of a given operator
  public abstract int priority();

  // perfoms operation between left and right operand
  public abstract Operand execute(Operand leftOperand, Operand rightOperand);

  // variable and constructor gives subclasses a way to store the token for later
  private final String token;

  protected Operator(String token) {
    this.token = token;
  }

  // checks whether token is in HashMap if not then it is added
  public static Operator getOperator(String token) {
    if (!operators.containsKey(token)) {
      switch (token) {
        case "+":
          operators.put("+", new AdditionOperator(token));
          break;
        case "-":
          operators.put("-", new SubtractionOperator(token));
          break;
        case "*":
          operators.put("*", new MultiplicationOperator(token));
          break;
        case "/":
          operators.put("/", new DivisionOperator(token));
          break;
        case "^":
          operators.put("^", new SquareOperator(token));
          break;
        case "(":
          operators.put("(", new leftParanthesesOperator(token));
          break;
        case ")":
          operators.put(")", new rightParanthesesOperator(token));
      }
    }
    // returns instance of the Operator class
    return operators.get(token);
  }

  // implements methods priority() and execute() depennding on the type of operator

  // checks if token is a valid operator
  public static boolean check(String token) {
    if (token.contains("+") || token.contains("-") ||
        token.contains("*") || token.contains("/") ||
        token.contains("^") || token.contains("(") ||
        token.contains(")")) {
      return true;
    } else {
      return false;
    }
  }
}
