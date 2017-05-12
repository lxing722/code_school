package project;

import java.util.*;

public class CheckExpression {
	
	private Stack<String> stack = new Stack<String>();
	
	public CheckExpression(){
		
	}
	public void check(Tokenizer tokenizer) throws TokenException, SyntaxErrorException, LexicalErrorException{
		Token previous = tokenizer.peekNextToken();
		while(tokenizer.hasNextToken()){
			Token t = tokenizer.peekNextToken();
			if(t.isDelimiter()){
				if(t.getDelimiter().equals("("))
					stack.push(t.getDelimiter());
				if(t.getDelimiter().equals(")")){
					if(stack.isEmpty())
						throw new SyntaxErrorException("Syntax error: mismatch " + t);
					else
						stack.pop();
				}
			}
			if(t.isOperator()){
				if(previous.isOperator())
					throw new SyntaxErrorException("Syntax error: malformed expression");
			}
			if(t.isEqual())
				throw new SyntaxErrorException("Syntax error: malformed expression");
			previous = t;
			tokenizer.readNextToken();
		}
		if(!stack.isEmpty())
			throw new SyntaxErrorException("Syntax error: mismatch [OPENBAR]");
	}
}
