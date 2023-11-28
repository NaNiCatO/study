import js
from pydide import create_proxy


output = document.getElementById('result')
currentExpression = ''

# Keyup event handler
def keyup(event):
    key = event.key

    # Check if the pressed key is a number or an operator
    if key.isnumeric() or key in ['+', '-', '*', '/']:
        currentExpression += key
        output.innerHTML = currentExpression
    elif key == 'Enter' or key == '=':
        try:
            # Try to evaluate the expression when Enter key is pressed
            result = eval(currentExpression)
            output.innerHTML = result
            currentExpression = str(result)  # Store the result as the new expression
        except Exception as error:
            output.innerHTML = 'Error'
            currentExpression = ''  # Clear the expression in case of an error
    elif key == 'Backspace':
        # Handle backspace to remove the last character
        currentExpression = currentExpression[:-1]
        output.innerHTML = currentExpression
    elif key.lower() == 'c':
        # Clear the expression when 'C' or 'c' is pressed
        currentExpression = ''
        output.innerHTML = '0'

event_proxy = create_proxy(keyup)
document.addEventListener('keyup', event_proxy)