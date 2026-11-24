# Market predictor/simulator project

## Aim and scope of the project
This project is a one-week project written in C, with python being used for data visualization and plotting for comparison of results.

The point of the project is to build a larger project in C than what the exercises of my KN King book provides, and to learn about quantitative implementations.

The aim of the project is to make a trading simulator, which uses market values and predicts how the market will increase/decrease over the next 24 hours with a confidence in the change of the market.
It will be done without machine-learning models, only mathematical modelling. The number to beat is the expected increase of the market of 7%/year or 0.03%/day, including a cost of betting.
The model pretends to trade futures. It calculates it's own theoretical gain/loss from the bets it placed and the commission costs.

For testing, I will also build a monteCarlo based program for simulating market data to use for developing the model in the first place. This program will take a function bias,
simulating the market "direction", and a stochastic variation around this bias value. 

