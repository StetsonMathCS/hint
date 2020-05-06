#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <xapian.h>
#include <vector>
using namespace std;


int main() {
    Xapian::WritableDatabase db("test.idx", Xapian::DB_CREATE_OR_OPEN);
	vector<string> terms; 		// example vector to show it working
    terms.push_back("word");
    terms.push_back("the");
    terms.push_back("hint");
    terms.push_back("apple");
    terms.push_back("of");
    
	Xapian::TermGenerator termgenerator;

    // Use a "stemmer", which reduces words like "root", "rooting", "rooted", etc. to their common stem "root"
    // before adding to the index. Queries will need to be stemmed, too (see below).
    termgenerator.set_stemmer(Xapian::Stem("en"));
	int i = 0;
    for(std::vector<string>::iterator it = terms.begin(); it != terms.end(); it++) {
    	Xapian::Document doc;    				//Xapian stores each term in a "document" then compares search to the documents 
     	string body = terms[i]; 			
		doc.set_data(body);						//adding the term to the document
 		termgenerator.set_document(doc);		//this is for indexing so you dont get multiple of the same documents
		termgenerator.index_text(body);			
		string idterm = "Term" + terms[i];
        doc.add_boolean_term(idterm);
        db.replace_document(idterm, doc);
		i++;
	}
    // Now let's search
        int offset = 0;
        int pagesize = 10;
        Xapian::QueryParser queryparser;
        string querystring;
        while(true)
        {
            cout << "Enter a search query (or \"quit\"): ";
            getline(cin, querystring);
            if(querystring == "quit")
            {
                break;
            }
            queryparser.set_stemmer(Xapian::Stem("en"));
            queryparser.set_stemming_strategy(queryparser.STEM_SOME);
            Xapian::Query query = queryparser.parse_query(querystring);
            Xapian::Enquire enquire(db);
            enquire.set_query(query);
            Xapian::MSet mset = enquire.get_mset(offset, pagesize);
    
            cout << "Showing results " << offset + 1 << "-" << min(offset + pagesize, (int)mset.size())
                 << " of " << mset.size() << endl;
            for(Xapian::MSetIterator m = mset.begin(); m != mset.end(); ++m)
            {
                Xapian::docid did = *m;
                cout << m.get_rank() + 1 << ": DocID " << did << ", match score: " << m.get_percent() << endl;
    
                string data = m.get_document().get_data();
                cout << data << endl << endl << endl;
            }
            cout << endl << endl;
        }
    return 0;
}
