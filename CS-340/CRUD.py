from pymongo import MongoClient
from bson.objectid import ObjectId

class CRUD(object):
    #create a CRUD class for use with MongoDB

    def __init__(self, username='aacuser', password='TSM4life', dbname='AAC', collection='animals'):
        
        # Constructor for CRUD class.
        
        # Parameters:
        #     username: MongoDB username (default: 'aacuser')
        #     password: MongoDB password (default: 'TSM4life')
        #     dbname: MongoDB database name (default: 'AAC')
        #     collection: MongoDB collection name (default: 'animals')
        
        
        #Initialize MongoDB connection param
        self.client = MongoClient('mongodb://%s:%s@nv-desktop-services.apporto.com:31228' % (username, password))
        
        # Select the correct DB, in this case, AAC
        self.database = self.client[dbname]
        
        # Select the correct collection, in this case, animals
        self.collection = self.database[collection]

    def create(self, data):
       #  
       # Method to instert a document into a specified MongoDB database
       
       # Input:
       #     data: The document to be inserted.
           
       # Return:
       #     True if succesful, else False
           
        
        #Checks to make sure data is provided
        if data:
            try:
                self.collection.insert_one(data)
                return True
            except Exception as e:
                return False
        else:
            raise ValueError("Data parameter is empty")

    def read(self, search):
        #
        #Method that quesries for document(s) from a specified MongoDB collection
        
        #Input:
        #    search: Contains the key/value lookup pair to use with MongoDB driver find API call
        
        #Return:
        #    Result in a list if the command is successful, else an empty list    
        try:
            result = self.collection.find(search)
            return result
        except Exception as e:
            return str(e)
        
    def update(self, search, update_data):
        
        # Method to find and update documents in an existing database
            
        # Inputs: 
        #     search: Contains the key/value lookup pair to use with MongoDB driver find API call
            
        #     update_data: Contains the key/value pairs in the data type acceptable to the MongoDB driver 
        #     update_one() or update_many() API call.
            
        # Returns:
        #         The number of objects modified.
        
        
        try:
            result = self.collection.update_many(search, {"$set": update_data})
            return result.modified_count
        except Exception as e:
            print("Error", e)
            return 0
    
    def delete(self, search):
        
        # Method to query and remove documents from a specifed db and collection
        
        # Inputs:
        #     search: Contains the key/value lookup pair to use with MongoDB driver find API call
            
        # Returns:
        #     The number of objects removed.       
        
        try:
            result = self.collection.delete_many(search)
            return result.deleted_count
        except Exception as e:
            print("Error", e)
            return 0

