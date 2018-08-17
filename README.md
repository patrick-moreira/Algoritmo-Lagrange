<!DOCTYPE html>
<html>
#Lagrange Algorithm: Polynomial Interpolation
> The present project aims to implement the Joseph-Louis de Lagrange (1736-1813) polynomial interpolation algorithm for the resolution of a transport engineering problem.

<p>
DESCRIPTION: A transportation engineering study was conducted to determine an appropriate design of bicycle lanes. Data were collected on the width of the tracks and the average distance between bicycles and cars traveling. If the minimum safe distance between bicycles and cars traveling is 1.9 meters, determine the width of the corresponding track using two interpolator polynomials to solve the problem. </ p>

_Distance (m)_: <br />
`2.4, 1.5, 2.4, 1.8, 1.8, 2.9, 1.2, 3.0, 1.2` <br />
_Width (m)_: <br />
`2.9, 2.1, 2.4, 2.1, 1.8, 2.7, 1.5, 2.9, 1.5` 


## Running:

Once your computer has gcc installed, use the following command on the terminal:

To compile:
      `make`
      
To Execute:      
   _On Linux:_ `./lagrange points.txt`
            
   _On Windows:_ `lagrange.exe points.txt` 
           

## contributing
1. _Fork_ <br />
2. Create a _branch_ for your modification (`git checkout -b _branch-name_`) <br />
3. Do the _commit_ (`git commit -m '_commentary_'`) <br />
4. _Push_ (`git push origin _branch-name_`) <br />
5. Create a new _Pull Request_ <br />

</html>
