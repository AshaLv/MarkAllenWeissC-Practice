class Painter:
    @staticmethod
    def paint_tree(tree):
        import math
        '''this function needs acurate tree height which is for fn function 
        below. This fn function uses the height to get an odd number for root,
        with this odd number we can make every node take space equally each layer
        try:
            height = tree.get_height()
        except:
            height = math.floor(math.log(tree.size, 2)) 
        max_leave_number = 2 ** height
        layer = [tree.root]
        graph = ""
        atomic_space = " "
        '''f(n) = 2f(n-1) + 1 
        This fn function uses the height to get an odd number for root,
        with this odd number we can make every node take space equally each layer
        '''
        def fn(mheight):
            if mheight <= 1:
                return mheight
            return 2 * fn(mheight - 1) + 1
        tree_beautiful_odd_number = fn(height)
        while height >= 0:
            valuable = 0
            temp_layer = []
            leave_number = 2 ** height
            for node in layer:
                space = (leave_number + tree_beautiful_odd_number) * atomic_space 
                if node: data = node.data
                else: data = atomic_space
                graph += (space + data + space)
                '''
                Because nodes with parent dont take the space of theirs parents,
                so for balanced space painted, I add an atomic_space to the end of 
                every node except root
                '''
                if node != tree.root:
                    graph += atomic_space
                if node:
                    temp_layer.append(node.left_child)
                    temp_layer.append(node.right_child)
                else:
                    temp_layer.append(None)
                    temp_layer.append(None)
            height -= 1
            graph += "\n"
            layer = temp_layer
            tree_beautiful_odd_number = int((tree_beautiful_odd_number - 1) / 2)
        print(graph)

class BinaryTree:
    class Node:
        def __init__(self,data,parent=None,left_child=None,right_child=None):
            self.data = data
            self.parent = parent
            self.left_child = left_child
            self.right_child = right_child
    def __init__(self):
        self.root = None
        self.size = 0
    def search(self, data):
        node = self.root
        if not node:
            return None
        while node:
            if data < node.data:
                node = node.left_child
            elif data > node.data:
                node = node.right_child
            else:
                return node
        return None
    def insert(self, data):
        node = self.root
        if not node:
            self.root = BinaryTree.Node(data)
            self.size += 1
            return self.root
        else:
            while node:
                if data < node.data:
                    if not node.left_child:
                        node.left_child = BinaryTree.Node(data, parent=node)
                        self.size += 1
                        return node.left_child
                    node = node.left_child
                elif data > node.data:
                    if not node.right_child:
                        node.right_child = BinaryTree.Node(data, parent=node)
                        self.size += 1
                        return node.right_child
                    node = node.right_child
                else:
                    return node
        
tree = BinaryTree()
tree.insert("1")
tree.insert("2")
tree.insert("3")
tree.insert("4")

Painter.paint_tree(tree)