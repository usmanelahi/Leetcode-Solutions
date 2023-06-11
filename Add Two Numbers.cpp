    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }

        return addNode(l1, l2, 0);
    }

    public static ListNode addNode(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) {
            return null;
        }

        if (l1 != null) {
            carry += l1.val;
            l1 = l1.next;
        }

        if (l2 != null) {
            carry += l2.val;
            l2 = l2.next;
        }

        ListNode addNode = new ListNode(carry % 10);
        carry = carry / 10;
        addNode.next = addNode(l1, l2, carry);
        return addNode;
    }