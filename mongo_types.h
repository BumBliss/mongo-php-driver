/**
 *  Copyright 2009 10gen, Inc.
 * 
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

PHP_FUNCTION( mongo_bindata___construct );
PHP_FUNCTION( mongo_bindata___toString );
zval* bson_to_zval_bin(char*, int, int TSRMLS_DC);
int zval_to_bson_bin(zval **, char**, int* TSRMLS_DC);

PHP_FUNCTION( mongo_code___construct );
PHP_FUNCTION( mongo_code___toString );
zval* bson_to_zval_code(const char*, zval* TSRMLS_DC);
void zval_to_bson_code(zval**, char**, mongo::BSONObjBuilder* TSRMLS_DC);

PHP_FUNCTION( mongo_date___construct );
PHP_FUNCTION( mongo_date___toString );
zval* bson_to_zval_date(unsigned long long TSRMLS_DC);
unsigned long long zval_to_bson_date(zval** TSRMLS_DC);

PHP_FUNCTION( mongo_id___construct );
PHP_FUNCTION( mongo_id___toString );
zval* bson_to_zval_oid(const mongo::OID oid TSRMLS_DC);
void zval_to_bson_oid(zval**, mongo::OID* TSRMLS_DC);

PHP_FUNCTION( mongo_regex___construct );
PHP_FUNCTION( mongo_regex___toString );
zval* bson_to_zval_regex(char*, char* TSRMLS_DC);
void zval_to_bson_regex(zval**, char**, char** TSRMLS_DC);
