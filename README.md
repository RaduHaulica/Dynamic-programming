i generate an array of movement costs and then calculate the best cost for each end position

highlights the performance benefits of using dynamic programming instead of just simple recursion

the number of calls for the first result is really high because it populates a large portion of the value cache, and subsequent calls benefit greatly from the information computed in the first pass.
