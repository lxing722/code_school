package project;
/*
 * Author: Liang Xing
 * This class is created to handle 
 * operators in the mathematical expression evaluator
 */
public class FunOp {
	//the name of operator
	public String name;
	//the number of operands
	public int num;
	//the priority of operator
	public int priority;
	
	//constructor
	public FunOp(Token T) throws TokenException {
		if(T.isDelimiter()){
			name = T.getDelimiter();
			num = 0;
			if(T.getDelimiter() == "(")
				priority = 0;
		}
		if(T.isOperator()){
			this.name = T.getOperator();
			if(T.getOperator().equals("~"))
				num = 1;
			else
				num = 2;
			if(T.getOperator().equals("+") || T.getOperator().equals("-"))
				priority = 1;
			else if(T.getOperator().equals("*") || T.getOperator().equals("/"))
				priority = 2;
			else if(T.getOperator().equals("^"))
				priority = 3;
			else
				priority = 4;
		}			
	}
}
