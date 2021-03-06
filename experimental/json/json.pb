
#include "base.pb"

JSONText :
            JSONObject | JSONObject | JSONObject |
            JSONObject | JSONObject | JSONObject |
            JSONObject | JSONObject | JSONObject |
            JSONValue ;

JSONValue :
            JSONObject |
            JSONNullLiteral |
            JSONBooleanLiteral |
            JSONArray |
            JSONString |
            JSONNumber ;

JSONObject : "{" JSONObjectMembers "}" ;

JSONObjectMembers :
             BigJSONMemberList | BigJSONMemberList |
             BigJSONMemberList | BigJSONMemberList |
             JSONMemberList | JSONMemberList | JSONMemberList |
             JSONMemberList | JSONMemberList | JSONMemberList |
             JSONMemberList | JSONMemberList | JSONMemberList |
             "" ;

BigJSONMemberList : JSONMemberList "," JSONMemberList ","
                    JSONMemberList "," JSONMemberList ","
                    JSONMemberList "," JSONMemberList ","
                    JSONMember ;

JSONMemberList : JSONMember | JSONMemberList "," JSONMember ;
JSONMember : JSONString ":" JSONValue ;

JSONArray : "[" JSONArrayMembers "]" ;
JSONArrayMembers : JSONElementList | "" ;
JSONElementList : JSONValue | JSONElementList "," JSONValue ;

JSONString : StringLiteral | LongStringLiteral | EscapedStringLiteral ;
JSONNumber : Integer ;
JSONNullLiteral : "null" ;
JSONBooleanLiteral : "true" | "false" ;
