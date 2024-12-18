const ull mask = mt19937_64(time(nullptr))();
ull shift(ull x) {
  x ^= mask;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  x ^= mask;
  return x; }
void dfs(int u) { // edge[父] = {子}
  tree_hash[u] = 1;
  for (int v : edge[u]) {
    dfs(v);
    tree_hash[u] += shift(tree_hash[v]);
} }