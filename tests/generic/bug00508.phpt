--TEST--
Test for PHP-508: Change BSON ID generation to use random "increment".
--SKIPIF--
<?php require_once dirname(__FILE__) ."/skipif.inc";?>
--FILE--
<?php
require_once dirname(__FILE__) . "/../utils.inc";
$m = new_mongo();
$c = $m->selectDB(dbname())->test;
$c->drop();

$d = array(
	array('c' => 0),
	array('c' => 1),
	array('c' => 2),
	array('c' => 3),
);

foreach ($d as $doc)
{
	$c->insert($doc);
	$id = $doc['_id']->__toString();

	var_dump($id);
	
	if ($doc['c'] == 0)	{
		/* For the first one, we make sure it doesn't end in 000000. It
		 * is technically possible, but very unlikely */
		echo preg_match('/000000$/', $id) ? "All zeroes :-(\n" : "All random!\n";
	} else {
		/* For subsequent once, we check whether it's one more than the
		 * last one. */
		$idInt = hexdec(substr($id, -6));

		echo ((($lastIdInt + 1) % 0x1000000) == $idInt) ? "One more\n" : "Something odd\n";
	}

	$lastIdInt = hexdec(substr($id, -6));
	unset($doc);
}
?>
--EXPECTF--
string(24) "%s"
All random!
string(24) "%s"
One more
string(24) "%s"
One more
string(24) "%s"
One more
