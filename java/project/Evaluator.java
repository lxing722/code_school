package project;

import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Evaluator {
	
	private Map<String, Double> variables = new HashMap<String,Double>();
	private Set<String> keywords = new HashSet<String>();
	private double last;
	private int precision;
	
	public Evaluator(){
		keywords.add("let");
		keywords.add("setprecision");
		keywords.add("reset");
		keywords.add("last");
		keywords.add("exit");
		keywords.add("load");
		keywords.add("save");
		keywords.add("saved");
		last = 0;
		precision = 6;
	}
	public String eval(Tokenizer tokenizer) throws TokenException,LexicalErrorException,SyntaxErrorException{
		try{
			if(tokenizer.hasNextToken()){
				Token t = tokenizer.peekNextToken();
				if(t.isNumber()||
					(t.isDelimiter()&&t.getDelimiter().equals("("))||
					(t.isIdentifier()&&variables.containsKey(t.getIdentifier()))||
					(t.isIdentifier()&&t.getIdentifier().equals("last"))||
					t.isOperator()&&t.getOperator().equals("~")
					){
					return Compute(tokenizer,variables);
				}
				else if(t.isIdentifier()&&
						!variables.containsKey(t.getIdentifier())&&
						!keywords.contains(t.getIdentifier()))
					throw new GeneralErrorException(t.getIdentifier()+" is not a variable");
				else if(t.isIdentifier()&&keywords.contains(t.getIdentifier())){
					if(t.getIdentifier().equals("setprecision")){
						return Precision(tokenizer);
					}			
					//the keyword let					
					if(t.getIdentifier().equals("let")){
						return Keywords_let(tokenizer);
					}
					// keywords reset
					if(t.getIdentifier().equals("reset")){
						return Keywords_reset(tokenizer);					
					}
					// keywords save
					if(t.getIdentifier().equals("save")){
						return Keywords_save(tokenizer);					
					}
					// keywords load
					if(t.getIdentifier().equals("load")){
						return Keywords_load(tokenizer);					
					}
					// keywords saved
					if(t.getIdentifier().equals("saved")){
						//return Keywords_saved(tokenizer);					
					}
				}				
				else throw new SyntaxErrorException("malformed expression");
			}
			return "Error: empty input";
		}
		catch(Exception e){
			return e.toString();
   		}
	}
	
	public String Compute(Tokenizer tokenizer,Map<String,Double> variables) throws GeneralErrorException, TokenException, LexicalErrorException, SyntaxErrorException{
		MathematicalEvaluator  math = new MathematicalEvaluator();
		math.computeResult(tokenizer,variables,last);
		last = math.getResult();
		return setprecision(last,precision);
	}
	public String setprecision(double d, int p){
		BigDecimal b = new BigDecimal(d);
		double d1 = b.setScale(p,BigDecimal.ROUND_HALF_UP).doubleValue();
		return d1+"";
	}
	public String Precision(Tokenizer tokenizer) throws TokenException,LexicalErrorException,SyntaxErrorException{
		tokenizer.readNextToken();
		if(!tokenizer.hasNextToken())
			return "current precision is "+precision;
		else{
			if(tokenizer.peekNextToken().isNumber()){
				precision = (int)tokenizer.peekNextToken().getNumber();
				return "precision set to "+precision;
			}
			else return "precision should be a number!";
		}
	}
	
	public String Keywords_let(Tokenizer tokenizer) throws TokenException,LexicalErrorException,SyntaxErrorException, GeneralErrorException{
			String s;
			tokenizer.readNextToken();
			if(tokenizer.hasNextToken()){
				if(!tokenizer.peekNextToken().isIdentifier())  throw new SyntaxErrorException("Please input an identifier");
			    s = tokenizer.readNextToken().getIdentifier();
			    if(keywords.contains(s)) throw new SyntaxErrorException(s+" should not be a variable");
				if(tokenizer.readNextToken().isEqual()){
					if(tokenizer.hasNextToken()){
						Compute(tokenizer,variables);
						variables.put(s,last);
					}
				return last+"";
				}
				else throw new SyntaxErrorException("No Equal_sign!");				
			}
			else{
				String output="";
				if(variables.size()==0)
					return "no variable defined";
				else{
					for(Map.Entry<String, Double> entry : variables.entrySet()){
						output=output+entry.getKey()+"="+entry.getValue()+" \n"; 
			        } 
					return output;
				}	
		   }	
	}
	
	public String Keywords_reset(Tokenizer tokenizer) throws TokenException,LexicalErrorException,SyntaxErrorException{
		tokenizer.readNextToken();
		String output="";
		if(tokenizer.hasNextToken()){
			do{
				String s=tokenizer.readNextToken().getIdentifier();
				if (keywords.contains(s)) throw new SyntaxErrorException(s+" is not a variable");
				output=output+s+" has been reset"+" \n";
				variables.remove(s);	
			}while(tokenizer.hasNextToken());						
			return output;				
		}	
		else{
			for(Map.Entry<String, Double> entry : variables.entrySet()){
				output=output+entry.getKey()+" has been reset"+" \n";
		    }
			variables.clear();
			return output;
		}
	}
	
	public String Keywords_save(Tokenizer tokenizer) throws GeneralErrorException,TokenException,LexicalErrorException,SyntaxErrorException,FileNotFoundException{
		tokenizer.readNextToken();
		String file_name;
		PrintStream output;
		if(tokenizer.peekNextToken().isString()){
			file_name=tokenizer.readNextToken().getString();
			output=new PrintStream(new File("src/project/"+file_name+".txt"));
			if(!tokenizer.hasNextToken()){		
				for(Map.Entry<String, Double> entry : variables.entrySet()){
					output.println(entry.getKey()+" "+entry.getValue()); 
		        }				
			}
			else{	
				String s;
				do{
					s=tokenizer.readNextToken().getIdentifier();
					if(variables.containsKey(s))
					output.println(s+variables.get(s));	
					else {
						output.close();
						throw new GeneralErrorException("Can't find this variables");
					}
				}while(tokenizer.hasNextToken());												
			}
			output.close();
			return "variables saved in "+file_name;
		}
		else throw new GeneralErrorException("Can't find a file_name");
	}
	
	public String Keywords_load(Tokenizer tokenizer) throws GeneralErrorException,TokenException,LexicalErrorException,SyntaxErrorException,FileNotFoundException{
		tokenizer.readNextToken();
		String file_name;
		Scanner input;
		if(tokenizer.hasNextToken()&&tokenizer.peekNextToken().isString()){
			file_name=tokenizer.readNextToken().getString();
			input=new Scanner(new File("src/project/"+file_name+".txt"));
			while(input.hasNextLine()){			
				String line=input.nextLine();			
				Scanner input_line = new Scanner(line);
				String name=input_line.next();
				double number=input_line.nextDouble();
				variables.put(name,number);
				input_line.close();
			}
			input.close();
			return file_name+" loaded";
		}
		else throw new GeneralErrorException("Can't find a file_name");
	}
	
	//public String Keywords_saved(Tokenizer tokenizer)  throws GeneralErrorException,TokenException,LexicalErrorException,SyntaxErrorException,FileNotFoundException{
		
	//}
}




