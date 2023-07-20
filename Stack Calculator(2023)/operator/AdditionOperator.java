package operator;

import operand.Operand;

public class AdditionOperator extends Operator {
//creates new instance of addition operator
    public AdditionOperator(String token) {
      super(token);
    }
//execute addition operation 
    public Operand execute(Operand leftOperand, Operand rightOperand) {
      return new Operand(leftOperand.getValue() + rightOperand.getValue());
    }
//set priority 
    @Override
    public int priority() {
      return 2;
    }
  }