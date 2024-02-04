import ZODB, ZODB.config
path = "./config.xml"
db = ZODB.config.databaseFromURL(path)
connection = db.open()
root = connection.root()


import account, BTrees.OOBTree

root.customer = BTrees.OOBTree.BTree()
root.customer['customer-1'] = account.Customer('Delta')
root.customer['customer-2'] = account.Customer('Emily')

