/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package blockchain;

import java.util.ArrayList;
import java.util.List;

public class Blockchain {

    public static void main(String[] args) {
        
        List<Block> blockChainList = new ArrayList<>();
        
        Block genesis = new Block("BlockChain", 0);
        blockChainList.add(genesis);
        Block helloBlock = new Block("Hello", blockChainList.get(blockChainList.size() - 1).getHash());
        blockChainList.add(helloBlock);
        Block worldBlock = new Block("World", blockChainList.get(blockChainList.size() - 1).getHash());
        blockChainList.add(worldBlock);
        
          
        System.out.println("---------------------");
        System.out.println("- BlockChain -");
        System.out.println("---------------------");
        System.out.println("Hash helloBlock"+ helloBlock.getHash());
        System.out.println("PreviousHash WorldBlock"+ worldBlock.getPreviousHash());

        System.out.println("---------------------");
        System.out.println("Is valid?: " + validate(blockChainList));
        System.out.println("---------------------");
        
        // corrupt block chain by modifying one of the block
        Block hiBlock = new Block("Hi", genesis.getHash());
        int index = blockChainList.indexOf(helloBlock);
        blockChainList.remove(index);
        blockChainList.add(index, hiBlock);
        
        System.out.println("Corrupted block chain by replacing 'Hello' block with 'Hi' Block");
        System.out.println("---------------------");
        System.out.println("- BlockChain -");
        System.out.println("---------------------");
        System.out.println("Hash hiBlock"+ hiBlock.getHash());
        System.out.println("PreviousHash WorldBlock"+ worldBlock.getPreviousHash());
        
        System.out.println("---------------------");
        System.out.println("Is valid?: " + validate(blockChainList));
        System.out.println("---------------------");
    }

    private static boolean validate(List<Block> blockChain) {
        
        boolean result = true;
        Block lastBlock = null;
        for (int i = blockChain.size() - 1; i >= 0; i--) {
            if (lastBlock == null) {
                lastBlock = blockChain.get(i);
            } else {
                Block current = blockChain.get(i);
                if (lastBlock.getPreviousHash() != current.getHash()) {
                    result = false;
                    break;
                }
                lastBlock = current;
            }
        }
        return result;
    }
}
