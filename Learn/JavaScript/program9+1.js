var cards = ['Diamond', 'Spade', 'Heart', 'Club'];

var currentCard = 'Heart';

var i=0;

while (currentCard !== 'Spade') {
  console.log(currentCard);

  var randomNumber = Math.floor(Math.random() * 4);
  i++;

  currentCard = cards[randomNumber];
}

console.log('Found a Spade!' + i);
