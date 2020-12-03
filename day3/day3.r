library(stringr)

terrain <- read.csv2("./input", header=FALSE, sep="")

# First Star ---------------------------------------------------------------
p1_slope <- c(x = 3, y = 1)

width <- str_length(terrain[1,1])
count_trees <- function(slope) {
  treecount = 0
  loc <- c(x = 1, y = 1)
  while (loc['y'] <= dim(terrain)[1]) {
    x <- loc['x']
    if (x == 0) x <- width
    y <- loc['y']
    row = terrain[y, 1]
    #print(loc)
    if (substr(row, x, x) == '#') {
      rowdebug <- paste0(substr(row, 0, x-1), 'X', substr(row, x+1, str_length(row)))
      #print(paste(rowdebug,"Tree at ", paste(loc, collapse = ',')))
      treecount <- treecount + 1
    } else {
      rowdebug <- paste0(substr(row, 0, x-1), 'O', substr(row, x+1, str_length(row)))
      #print(paste(rowdebug,"No tree at ", paste(loc, collapse = ',')))
    } 

    loc['x'] <- (x + slope['x']) %% (width)
    loc['y'] <- y + slope['y']
  }
  return(treecount)
}

print(count_trees(p1_slope))


# Second Star -------------------------------------------------------------

allslopes = list(c(x = 1, y = 1),
                 c(x = 3, y = 1), 
                 c(x = 5, y = 1), 
                 c(x = 7, y = 1), 
                 c(x = 1, y = 2))

treecounts <- sapply(allslopes, count_trees)
print(treecounts)
print(Reduce(`*`, treecounts))
