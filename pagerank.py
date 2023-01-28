import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
class pagerank:
    def __init__(self,mat):
        self.mat = mat
        self.pagerank = []#creating a list to hold the pagerank values of all the nodes in the graph
    
    def pagerank_calc(self,iter = 50,damping = 0.85):
        """
        mat is a matrix (or a 2D array) that represents the adjacency matrix of a graph; if mat[i,j] = 1 -- it means that an edge goes from i to j

        iter: int, optional,
        It represents the number of iterations that should take.
        Ideally pagerank calculation goes on till the pagerank values converge (or the diff between two consecutive iteration results are less than a particular threshold)

        damping: float, optional
        This is the value that represents the probabilty that the 'random surfer' will continue clicking
        """
        N = self.mat.shape[1]
        self.pagerank = np.ones(N) / N #this is the initialised pagerank values: 1/N
        print("Initially the pagerank of all the nodes/webpages/articles are\n",self.pagerank)

        iter_step = 1
        while(iter_step<=iter):
            temp_pagerank = self.pagerank #storing the pagerank values in a temporary array
            self.pagerank = np.zeros(N)/N

            for int_node_num in range(N):
                for ext_node_num in range(N):
                    if(self.mat[ext_node_num,int_node_num]==1):
                        k = 1
                        outgoing_links = 0
                        while(k<N):
                            if(self.mat[ext_node_num,k]==1):
                                outgoing_links+=1
                            k+=1
                        self.pagerank[int_node_num]+=temp_pagerank[ext_node_num]*(1/outgoing_links)
            print("After {}th step\n".format(iter_step))
            print(self.pagerank)
            iter_step+=1
        for i in range(len(self.pagerank)):
            self.pagerank[i] = (1 - damping) + damping*self.pagerank[i]
        print("The final pagerank values are\n",self.pagerank)
        return self.pagerank
if __name__ == "__main__":
    
    #drawing it as a graph
    graph = nx.DiGraph()
    list_of_nodes = np.arange(1,7)
    graph.add_nodes_from(list_of_nodes)#there are 6 nodes in the graph
    graph.add_edges_from([(1,2),(1,3),(3,1),(3,2),(3,5),(4,5),(4,6),(5,4),(5,6),(6,4)])#adding its edges

    fig,ax = plt.subplots()
    p = nx.draw(graph,with_labels = True) # drawing the graph
    ax.set_title("The graph")
    plt.show()


    adj_matrix = np.array([#the adjacency matrix
        [0,1,1,0,0,0],
        [0,0,0,0,0,0],
        [1,1,0,0,1,0],
        [0,0,0,0,1,1],
        [0,0,0,1,0,1],
        [0,0,0,1,0,0]
    ])
    print("The adjacency matrix of the graph is \n",adj_matrix)

    obj = pagerank(adj_matrix)#creating an instance of the class 'pagerank'
    final_pagerank_val = obj.pagerank_calc(iter = 2,damping = 0.85)