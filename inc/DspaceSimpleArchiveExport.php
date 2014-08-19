<?php

/**
 * @file
 * Contains DspaceSimpleArchiveExport.
 */

/**
 * Represents a newspaper import session.
 *
 * The DspaceSimpleArchiveExport class describes a full DSpace
 * export in the Simple Archive format.
 */
class DspaceSimpleArchiveExport {
  /**
   * Constructs an DspaceSimpleArchiveExport object.
   *
   * @param string $import_path
   *   The absolute path to the DSpace simple archive format export
   */
  public function __construct($import_path) {
    $this->importPath = $import_path;
  }
}
