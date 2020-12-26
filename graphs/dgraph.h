#pragma once
#include <bits/stdc++.h>

template <typename I>
class dgraph
{
public:
    class dedge
    {
    public:
        I from;
        I to;
        I weight;
        dedge(I from, I to, I weight)
        {
            this->from = from;
            this->to = to;
            this->weight = weight;
        }
    };

    I n;
    vector<vector<I>> oadjl;
    vector<vector<I>> iadjl;
    vector<I> odeg;
    vector<I> ideg;

    dgraph(I n)
    {
        this->n = n;
        this->oadjl = vector<vector<I>>(n, vector<I>(0));
        this->iadjl = vector<vector<I>>(n, vector<I>(0));
        this->odeg = vector<I>(n, 0);
        this->ideg = vector<I>(n, 0);
    }

    void add_edge(I x, I y)
    {
        this->oadjl[x].push_back(y);
        this->iadjl[y].push_back(x);
        this->odeg[x]++;
        this->ideg[y]++;
    }

    void bfs(I x, vector<I> &level, vector<bool> &visted)
    {
        queue<I> snow;

        snow.push(x);
        level[x] = 0;

        while (!snow.empty())
        {
            auto t = snow.front();
            visted[t] = true;
            snow.pop();
            for (auto y : oadjl[t])
            {
                if (!visted[y])
                {
                    level[y] = level[t] + 1;
                    visted[y] = true;
                    snow.push(y);
                }
            }
        }
    }

    void dfs(I x, vector<I> &order, vector<I> &parent, vector<bool> &visted)
    {
        stack<I> snow;

        snow.push(x);
        I ct = 0;
        parent[x] = x;

        while (!snow.empty())
        {
            auto t = snow.top();
            visted[t] = true;
            order[t] = ct;
            ct++;
            snow.pop();
            for (auto y : oadjl[t])
            {
                if (!visted[y])
                {
                    order[y] = ct;
                    parent[y] = t;
                    ct++;
                    visted[y] = true;
                    snow.push(y);
                }
            }
        }
    }

    // need to complete section

    I tuckers_algorithm()
    {
    }

    void floyd_warshall(vector<vector<I>> &d)
    {
        d = this->adjm;
        for (I k = 0; k < n; k++)
        {
            for (I i = 0; i < n; i++)
            {
                for (I j = 0; j < n; j++)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    I grith()
    {
        // length of shortest cycle
    }

    void bridges(vector<pair<I, I>> &bridges)
    {
        stack<I> st;
        stack<I> back_vertex;
        vector<I> processed(this->n, -1);
        st.push(0);

        while (!st.empty())
        {
            I x = st.top();
            st.pop();
            processed[x] = 1;
            for (auto y : this->adj[x])
            {
                if (processed[y] == 1)
                {
                }
                else if (processed[y] == 0)
                {
                }
                else
                {
                    st.push(y);
                    processed[y] = 0;
                }
            }
        }
    }

    void prims()
    {
        set<pair<I, I>> pq;
        pq.insert(make_pair(0, 0));
        for (I i = 1; i < this->n; i++)
        {
        }
    }

    I dinics_algorithm()
    {
        I max_flow;

        return max_flow;
    }

    I connected_components(vector<I> &component)
    {
        component.assign(this->n, -1);

        I c = 0;
        I at = 0;

        while (at < this->n)
        {
            // do bfs for each vertex and get the component indexed
            queue<I> snow;
            snow.push(at);

            while (!snow.empty())
            {
                auto t = snow.front();
                component[t] = c;
                snow.pop();
                for (auto y : adjl[t])
                {
                    if (component[y] == -1)
                    {
                        component[y] = c;
                        snow.push(y);
                    }
                }
            }
            c++;
            while (component[at] != -1 && at < this->n)
                at++;
        }

        return c;
    }

    void topological_sort()
    {
    }

    // utils
    void print_deg()
    {
        for (I i = 0; i < this->n; i++)
        {
            cout << "[ " << i << ":" << this->ideg[i] << "," << this->odeg[i] << " ], ";
        }
        cout << endl;
    }

    void print_adjl()
    {
        I i = 0;
        cerr << "Out adj\n";
        for (auto x : this->oadjl)
        {
            cout << i << ": ";
            for (auto y : x)
            {
                cout << y << ", ";
            }
            cout << endl;
            i++;
        }

        i = 0;
        cerr << "In adj\n";
        for (auto x : this->iadjl)
        {
            cout << i << ": ";
            for (auto y : x)
            {
                cout << y << ", ";
            }
            cout << endl;
            i++;
        }
    }

};
