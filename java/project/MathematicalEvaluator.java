package project;
/*
 * Author: Liang Xing
 * This class is created to evaluate mathematical expression.
 */
import java.util.*;

public class MathematicalEvaluator {
	
	//A stack to store operator.
	private Stack<Token> operator = new Stack<Token>();
	
	//A stack to store values like numbers, variables.
	
	private Stack<Double> value = new Stack<Double>();
	
	//A stack to store open bars to check bar balance.
	private Stack<String> stack = new Stack<String>();
	
	//The final result of the mathematical expression.
	private double result;
	
	public MathematicalEvaluator(){
		result = 0;
	}
	
	//to get the final result of the mathematical expression.
	public void computeResult(Tokenizer tokenizer,Map<String,Double> variables,double last) throws GeneralErrorException, TokenException, LexicalErrorException, SyntaxErrorException{		

		//to ensure that the operator stack and the value stack are empty before compute;
		while(!operator.isEmpty())  
			operator.pop();
		while(!value.isEmpty())
			value.pop();
		Token previous = tokenizer.peekNextToken(); //to store the previous token 
		while(tokenizer.hasNextToken()){
			Token t = tokenizer.peekNextToken();
			//t is a "=" token
			if(t.isEqual())
				throw new SyntaxErrorException("malformed expression");
			//t is a number token
			else if(t.isNumber())
				value.push(t.getNumber());
			//t is a identifier token
			else if(t.isIdentifier()){
				if(variables.containsKey(t.getIdentifier()))
					value.push(variables.get(t.getIdentifier()));
				if(t.getIdentifier().equals("last"))
					value.push(last);				
			}
			//t is a delimiter token
			else if(t.isDelimiter())
				doDelimiter(t);
			//t is an operator token
			else if(t.isOperator())
				doOperator(t,previous);
			previous = t;
			tokenizer.readNextToken();
		}
		/*
		 * if the bar stack is not empty in the end,
		 * means that there are more open bars than closing bars
		 */
		if(!stack.isEmpty())
			throw new SyntaxErrorException("mismatch [OPENBAR]");
		while(!operator.isEmpty()){
			FunOp temp = new FunOp(operator.peek());
			if(temp.num == 1)
				value.push(computeOneOperand(value.pop(),operator.pop().getOperator()));
			else
				value.push(computeTwoOperands(value.pop(),value.pop(),operator.pop().getOperator()));
		}	
	}
	private void doDelimiter(Token t) throws TokenException, SyntaxErrorException, GeneralErrorException{
		if(t.getDelimiter().equals("(")){
			operator.push(t);
			stack.push(t.getDelimiter());
		}						
		if(t.getDelimiter().equals(")")){
			/*
			 * if the bar stack is empty,
			 * means that there are more closing bars than open bars.
			 */
			if(stack.isEmpty())
				throw new SyntaxErrorException("mismatch " + t);
			else
				stack.pop();
			while(!operator.peek().isDelimiter()){
				value.push(computeTwoOperands(value.pop(),value.pop(),operator.pop().getOperator()));
			}
			operator.pop();
		}
	}
	private void doOperator(Token t,Token previous) throws SyntaxErrorException, TokenException, GeneralErrorException{
		//check that if there are two successive operators
		if(previous.isOperator()&&!t.getOperator().equals("~"))
			throw new SyntaxErrorException("malformed expression");
		if(!operator.isEmpty()){
			FunOp thisOp = new FunOp(t);
			FunOp topOp = new FunOp(operator.peek());
			//compare the operator priority
			if(thisOp.priority <= topOp.priority){
				if(topOp.num == 1)
					value.push(computeOneOperand(value.pop(),operator.pop().getOperator()));
				else
					value.push(computeTwoOperands(value.pop(),value.pop(),operator.pop().getOperator()));
				operator.push(t);
			}
			else
				operator.push(t);
		}
		else
			operator.push(t);
	}
	private double computeTwoOperands(double a,double b,String str)throws GeneralErrorException{
		switch(str){
		case "+":
			return b+a;
		case "-":
			return b-a;
		case "*":
			return b*a;
		case "/":
			if(a == 0)
				throw new GeneralErrorException("division by zero");
			return b/a;				
		case "^":
			double result = 1;
			for(int i=0;i<a;i++)
				result *= b;
			return result;
		default: throw new GeneralErrorException("wrong operator");
		}		
	}
	private double computeOneOperand(double a,String str){
		return -a;
	}
	public double getResult(){
		result = value.peek();
		return result;
	}
}
