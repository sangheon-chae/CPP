class Node:
    def __init__(self, data):
        self.data = data
        self.link = None

class SList:
    def __init__(self):
        self.head = None
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def getNode(self, p):
        if p < 0 or p >= self.size: return None
        curr = self.head
        for _ in range(p):
            curr = curr.link
        return curr

    def insert(self, data, p):
        new_node = Node(data)
        if p == 0: # 맨 앞에 삽입
            new_node.link = self.head
            self.head = new_node
        else:
            before = self.getNode(p - 1)
            if before:
                new_node.link = before.link
                before.link = new_node
        self.size += 1

    def delete(self, p):
        if self.isEmpty() or p < 0 or p >= self.size: return None
        if p == 0: # 맨 앞 삭제
            self.head = self.head.link
        else:
            before = self.getNode(p - 1)
            if before:
                before.link = before.link.link
        self.size -= 1

    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.link
        print("None")