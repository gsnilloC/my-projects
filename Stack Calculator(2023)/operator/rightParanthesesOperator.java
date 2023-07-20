package operator;

import operand.Operand;

public class rightParanthesesOperator extends Operator {
    public rightParanthesesOperator(String token) {
      super(token);
    }

    @Override
    public Operand execute(Operand leftOperand, Operand rightOperand) {
      throw new UnsupportedOperationException("Cannot execute.");
    }
    //will use this later to check if token is right paranatheses
    public int priority() {
      return 0;
    }
  }