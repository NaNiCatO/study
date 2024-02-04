import ZODB, ZODB.config
import account, BTrees.OOBTree
import transaction
import account

path = "./config.xml"

db = ZODB.config.databaseFromURL(path)
connection = db.open()
root = connection.root()

if __name__ == "__main__" :
    root.customer = BTrees.OOBTree.BTree()
    root.customer['Dave'] = account.Customer('Dave')
    d = root.customer['Dave']
    root.customer['Jone'] = account.Customer('Jone')
    j = root.customer['Jone']

    print("Create Account:")
    b1 = d.addAccount(account.SavingsAccount(400, d, 1))
    b2 = j.addAccount(account.CurrentAccount(200, j, 5000))
    d.printStatus()
    j.printStatus()

    print("\nDeposit 500 to Account 2")
    b2.deposit(500)
    b2.printStatus()

    print("\nWithdraw 200 from Account 1")
    b1.withdraw(200)
    b1.printStatus()

    print("\nTransfer 150 from Account 2 to Account 1")
    b2.transfer(150, b1)
    b1.printStatus()
    b2.printStatus()

    transaction.commit()
