;; 
;; load google calendar
;;
;; author: evan jones
;;

(ql:quickload '(:drakma :cl-ppcre) :silent t)

(defpackage calendar
  (:use :common-lisp :cl-ppcre))

(in-package calendar)

(defparameter *url* "https://calendar.google.com/calendar/ical/evan.peter.jones%40gmail.com/private-2f9edde9e0ab999456847eaf507d680d/basic.ics")
(defparameter *ical-properties* '("EVENT" "DTSTART" "DTEND" "RRULE"))

(defun file-to-string (stream)
  "read a file stream into a string (currently returns a cons list, yikes)"
  (if stream
      (loop for line = (read-line stream nil)
           while line
           collect line)
      (format t "stream init is nil")))

(defun save-to-ical-file (file file-name)
  "read the result of an HTTP request to disk"
  (if file
      (with-open-file (str file-name 
                           :direction :output
                           :if-does-not-exist :create
                           :if-exists :append)
        (format str file))
      (format t "http request returned nil")))

(defun get-ical-file (url)
  (let ((file-name "cal.ics"))
    "handle a request to a url"
    (if (probe-file file-name)
        (file-to-string (open file-name))
        (progn
          (save-to-ical-file (drakma:http-request url) file-name)
          (get-ical-file file-name)))))

;; todo : make sure get-ical-file returns as string instead of cons list
;;; then split string by VEVENTS, then maybe learn CLOS so we can create dynamic
;;; objects using the string data. 

(defvar ical-file (get-ical-file *url*))
