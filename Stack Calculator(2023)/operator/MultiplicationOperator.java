package operator;

import operand.Operand;

public class MultiplicationOperator extends Operator {
    public MultiplicationOperator(String token) {
      super(token);
    }

    @Override
    public Operand execute(Operand leftOperand, Operand rightOperand) {
      return new Operand(leftOperand.getValue() * rightOperand.getValue());
    }

    @Override
    public int priority() {
      return 3;
    }
  }