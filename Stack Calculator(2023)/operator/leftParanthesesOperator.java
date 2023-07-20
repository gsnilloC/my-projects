package operator;

import operand.Operand;

public class leftParanthesesOperator extends Operator {
    public leftParanthesesOperator(String token) {
      super(token);
    }

    @Override
    public Operand execute(Operand leftOperand, Operand rightOperand) {
      throw new UnsupportedOperationException("Cannot execute.");
    }
    //will use this later to check if token is left paranatheses
    public int priority() {
      return 1;
    }
  }