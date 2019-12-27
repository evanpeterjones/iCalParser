;; 
;; load and parse google calendar -- currently only downloads my google calendar
;;
;; author: evan jones
;;

(ql:quickload '(:drakma :cl-ppcre :str) :silent t)

;; (load "file-type.lisp") ehhhh

(defpackage calendar
  (:use :common-lisp :cl-ppcre :file-type-utility))

(in-package calendar)

(defparameter *url* "https://calendar.google.com/calendar/ical/evan.peter.jones%40gmail.com/private-2f9edde9e0ab999456847eaf507d680d/basic.ics")
(defparameter *ical-properties* '("EVENT" "DTSTART" "DTEND" "RRULE") "these are properties described by the ICS international standard")

(defun test-function () "it works!")

(defun time-convert () "also works")

(defun stand () ".")

(defmacro call-field (items)
  `(funcall (cdr ,items)))

(defparameter *fields* '(("EVENT" . #'stand)
                         ("DTEND" . #'stand)
                         ("RRULE" . #'stand)
                         ("DTSTART" . #'time-convert)
                         ("DAMN" . #'test-function)))

(defun file-to-string (file-name)
  "read a file stream into a string"
  (with-open-file (stream file-name :if-does-not-exist nil)
    (let ((data (make-string (file-length stream))))
      (read-sequence data stream)
      data)))

(defun save-to-ical-file (file file-name)
  "read the result of an HTTP request to disk"
  (if file
      (with-open-file (str file-name 
                           :direction :output
                           :if-does-not-exist :create
                           :if-exists :append)
        (format str file))
      (format t "http request returned nil")))

(defun parse-all (file-list)
  (let ((data-list (str:split #\ file-list)))
    (loop for item in data-list 
       collect (str:split ":" (str:trim item)))))

(defun next-n (ical-file &optional (n 3))
  (let ((ical (str:split #\ ical-file)))
    ))

(defun read-ical-file (url)
  "handle requesting ical file from a url"
  (let ((file-name "cal.ics"))
    (if (not (probe-file file-name))
        (save-to-ical-file (drakma:http-request url) file-name))
    (file-to-string file-name)))

;; todo : make sure get-ical-file returns as string instead of cons list
;;; then split string by VEVENTS, then maybe learn CLOS so we can create dynamic
;;; objects using the string data. 

(defvar f-ical (read-ical-file *url*))

(defun comment (&optional rest) nil)

(comment
 (defun vector-to-list (vect)
   (loop for i from 0 to (- (length vect) 1) collect (aref vect i))))

