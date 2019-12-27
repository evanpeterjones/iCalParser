(ql:quickload :cl-ppcre)

(defpackage file-type-utility
  (:use :common-lisp :cl-ppcre))

(defparameter *filetypes*
  '((ics "ics")))

(defun verify-file-type (file-name)
  "verify that a file is the correct types"
  ;; todo : implement file-type validation with file content
  (cl-ppcre:scan ".ics" file-name))
