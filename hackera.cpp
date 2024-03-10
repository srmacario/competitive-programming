import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class TextEditor {
    private enum OperationType{WRITE, DELETE};
    
    public class TextOperation{
        public OperationType type;
        public char operatedChar;
        
        public TextOperation(OperationType _type, char _operatedChar){
            type = _type;
            operatedChar = _operatedChar;
        }
        public TextOperation(OperationType _type){
            type = _type;
        }
    }
    //redo only redoes if it write or delete not happened
    private Stack<TextOperation> textOperations, redoOperations;
    
    public TextEditor(){
        textOperations = new Stack<TextOperation>();
        redoOperations = new Stack<TextOperation>();
    }
    
    private void popAllRedoOperations(){
        while(!redoOperations.empty()) redoOperations.pop();
    }
    
    public void write(char c) {
        TextOperation currentOperation = new TextOperation(OperationType.WRITE, c);
        textOperations.add(currentOperation);
        popAllRedoOperations();
        
    }
    
    public void delete() {
        TextOperation currentOperation = new TextOperation(OperationType.DELETE);
        textOperations.add(currentOperation);
        popAllRedoOperations();
    }
    
    public String print() {
        StringBuilder ansBuilder = new StringBuilder();
        for (TextOperation op : textOperations) {
            if (op.type == OperationType.WRITE) ansBuilder.append(op.operatedChar);
            if (op.type == OperationType.DELETE){
                if(ansBuilder != null && ansBuilder.length() > 0) ansBuilder.deleteCharAt(ansBuilder.length() - 1);
            }
        }
        return ansBuilder.toString();
    }
    
    public void undo() {
        if(!textOperations.empty()) redoOperations.push(textOperations.pop());
    }
    
    public void redo() {
        if(!redoOperations.empty()) textOperations.push(redoOperations.pop());
    }
}