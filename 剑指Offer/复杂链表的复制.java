public class Solution {
    public RandomListNode Clone(RandomListNode pHead){
        if (pHead == null) {
            return null;
        }
        //复制每个节点并插入到原节点后面
        RandomListNode curr = pHead;
        while (curr != null) {
            RandomListNode clone = new RandomListNode(curr.label);
            clone.next = curr.next;
            curr.next = clone;
            curr = clone.next;
        }
        //处理random的指向
        curr = pHead;
        while (curr != null) {
            if (curr.random != null) {
                curr.next.random = curr.random.next;
            }
            curr = curr.next.next;
        }
        //最后一步,拆分链表
        curr = pHead;
        RandomListNode pHeadClone = curr.next;
        RandomListNode temp;
        while (curr.next != null) {
            temp = curr.next;
            curr.next = temp.next;
            curr = temp;
        }
        return pHeadClone;
    }
}
