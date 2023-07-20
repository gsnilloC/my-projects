package evaluator;

import java.util.*;
import operand.Operand;
import operator.Operator;

public class Evaluator {
    private Stack<Operand> operandStack;
    private Stack<Operator> operatorStack;

    private StringTokenizer tokenizer;
    private static final String DELIMITERS = "+-*^/()"; // DELIMITERS was modified to include parenthesis

    public Evaluator() {
        //creating the two stacks that will be used by algorithm
        operandStack = new Stack<>();
        operatorStack = new Stack<>();
    }

    public int eval(String expression) {
        String token;

        // The 3rd argument is true to indicate that the delimiters should be used as tokens too.
        // Added "\s+" to match whitespaces and replaces them with empty strings
        // Without this addition, kept getting an error
        this.tokenizer = new StringTokenizer(expression.replaceAll("\\s+", ""), DELIMITERS, true);

        //as long as there is more tokens to be processed
        while (this.tokenizer.hasMoreTokens()) {
            // filter out spaces
            if (!(token = this.tokenizer.nextToken()).equals(" ")) { // filter out spaces
                // if token is operand push into operand stack
                if (Operand.check(token)) {
                    operandStack.push(new Operand(token));
                    // if not print error and exit
                } else {
                    if ((!Operator.check(token))) {
                        System.out.println("*****invalid token******");
                        System.exit(1);
                        ;
                    }
                    // token has to be operator at this point, so create new operator instance
                    Operator newOperator = Operator.getOperator(token);

                    // if operator is "(" and operator stack is empty push "(" into stack
                    if ((operatorStack.isEmpty()) || (newOperator.priority() == 1)) {
                        operatorStack.push(newOperator);
                    } else {
                        // if token is ")" keep procesing operand stack until we find "("
                        if (newOperator.priority() == 0) {
                            while (operatorStack.peek().priority() != 1) {
                                Operator oldOpr = operatorStack.pop();
                                Operand op2 = operandStack.pop();
                                Operand op1 = operandStack.pop();
                                operandStack.push(oldOpr.execute(op1, op2));;
                            }
                            // if token is "(" pop it out os operator stack
                            if (operatorStack.peek().priority() == 1) {
                                operatorStack.pop();
                            }
                        } else {
                            // deal with the rest of the operators
                            // as long as top of operator stack has highest prirotiy and not empty, process operands
                            while ((operatorStack.peek().priority() >= newOperator.priority())) {
                                Operator oldOpr = operatorStack.pop();
                                Operand op2 = operandStack.pop();
                                Operand op1 = operandStack.pop();
                                operandStack.push(oldOpr.execute(op1, op2));
                                // stop from peaking empty stack
                                if (operatorStack.isEmpty())
                                    break;
                            }
                            // push in the highest priority operator
                            operatorStack.push(newOperator);
                        }
                    }

                }
            }
        }
        // process stack until operator is empty
        while (!operatorStack.isEmpty()) {
            Operator oldOpr = operatorStack.pop();
            Operand op2 = operandStack.pop();
            Operand op1 = operandStack.pop();
            operandStack.push(oldOpr.execute(op1, op2));
        }
        // get final value and return it
        return operandStack.peek().getValue();
    }

    public static void main(String[] args) {
        Evaluator evaluator = new Evaluator();

        for (String arg : args) {
            System.out.format("%s = %d\n", arg, evaluator.eval(arg));
        }
    }
}