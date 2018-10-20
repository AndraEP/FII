function takeOrder (topping, crustType)
{
  console.log('Order: ' + crustType + ' pizza topped with ' + topping);
}

takeOrder('bacon', 'thin crust');
takeOrder('bacon', 'thin crust');
takeOrder('bacon', 'thin crust');







var orderCount = 0;

function takeOrder (topping, crustType)
{
  console.log('Order: ' + crustType + ' pizza topped with ' + topping + '.');
  orderCount++;
}

function getSubTotal (itemCount)
{
  return itemCount * 7.5;
}

function getTax ()
{
  return getSubTotal(orderCount) * 0.06;
}

function getTotal ()
{
  return getSubTotal(orderCount) + getTax();
}

takeOrder('bacon', 'thin crust');
takeOrder('bacon', 'thin crust');
takeOrder('bacon', 'thin crust');

console.log(getSubTotal(orderCount));
console.log(getTotal());
