<?php

/**
 * @file
 * Contains DspaceSimpleArchiveExport.
 */

/**
 * Represents an entire DSpace archive group.
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


/**
 * Represents a DSpace archive item.
 *
 * The DspaceSimpleArchiveExportItem class describes an item in the
 * Simple Archive format.
 */
class DspaceSimpleArchiveExportItem {
  /**
   * Constructs an DspaceSimpleArchiveExportItem object.
   *
   * @param string $path
   *   The absolute path to the archive item
   */
  public function __construct($path) {
    $this->path = $path;
  }
}