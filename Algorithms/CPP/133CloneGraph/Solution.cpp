/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> record;
        if(node == NULL) {
            return node;
        }
        queue<UndirectedGraphNode*> q;
        q.push(node);

        while(!q.empty()) {
            UndirectedGraphNode* nextNode = q.front();
            q.pop();

            if( !record.count(nextNode) ) {
                UndirectedGraphNode* newNode = new UndirectedGraphNode(nextNode->label);
                record[nextNode] = newNode;
            }

            for(int i = 0; i < nextNode->neighbors.size(); i++) {
                UndirectedGraphNode *childNode = nextNode->neighbors[i];
                if( !record.count(childNode) ) {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(childNode->label);
                    record[childNode] = newNode;
                    q.push(childNode);
                }

                record[nextNode]->neighbors.push_back(record[childNode]);
            }
        }

        return record[node];
    }
};