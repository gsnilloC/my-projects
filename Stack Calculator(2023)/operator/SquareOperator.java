package operator;

import operand.Operand;

public class SquareOperator extends Operator {
    public SquareOperator(String token) {
      super(token);
    }

    @Override
    public Operand execute(Operand leftOperand, Operand rightOperand) {
      double squaredResult = Math.pow(leftOperand.getValue(), rightOperand.getValue());
      int roundedResult = (int) Math.round(squaredResult);

      return new Operand(roundedResult);
    }

    @Override
    public int priority() {
      return 4;
    }
  }