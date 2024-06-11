# MERMAID

```MERMAID
flowchart
  subgraph 1
  data_structure-->linear_data
  data_structure-->non_linear_data
  end
  subgraph 2
  linear_data-->static_data
  static_data--> array
  end
  subgraph 3
  linear_data-->dynamic_data
  dynamic_data-->queue
  dynamic_data-->stack
  dynamic_data-->linked_list
end
subgraph 4
  non_linear_data-->tree
  non_linear_data-->graphs;
  end
```
